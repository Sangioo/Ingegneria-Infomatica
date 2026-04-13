

//Importiamo express
const express = require('express')
const app = express() 

//Impostiamo la porta, (ecco perche mi ero collegato a localhost:3000)
const PORT = 3000
const HOST = '0.0.0.0' 


//IMPOSTIAMO LE ROTTE
const path = require("path") 
const ROOT = path.join(__dirname,'..','public') 

app.use(express.static(ROOT));  



//NAVIGAZIONE 
//Pagina home
app.get('/',(req,res)=>{
    res.sendFile(path.join(ROOT,'index.html'))
})

//Chi siamo
app.get("/chi-siamo",(req,res)=>{
    res.sendFile(path.join(ROOT,'chi-siamo','index.html'))
})

//Contatti
app.get("/contatti",(req,res)=>{
    res.sendFile(path.join(ROOT,'contatti','index.html'))  
})

//Ordina
app.get("/ordina",(req,res)=>{
    res.sendFile(path.join(ROOT,'ordina','index.html'))
})

//Profilo
app.get("/profilo", (req, res)=>{
    res.sendFile(path.join(ROOT, 'auth','profilo','index.html'))
})



//QUERY SU DATABASE
const {createClient} = require("@supabase/supabase-js") //da scaricare con npm
const supabaseApi = 'https://iblnubgcuixwisofranz.supabase.co' //"https://"" + < del progetto si trova nella url su supabase> + ".supabase.co"
const supabaseApiKey = 'sb_publishable_KsiaMEm63i8xkGs-r829yA_YYII_mKb' 
const supabase = createClient(supabaseApi, supabaseApiKey)



app.get('/api/frullati', async (req, res) => {

    const {data, error} = await supabase
        .from('frullati')
        .select(`
            id,
            nome,
            prezzo,
            img_path,
            categorie (nome)
        `) 

    if(error){
        res.send(500).json({error: 'An error occured while fetching data'}) 
        return
    }

    res.json(data) 
    
})

app.post('/api/ordina-frullato/:id', async (req, res) => {
    const idFrullato = req.params.id; 

    const idOrdineCasuale = Math.floor(Math.random() * 9000) + 1000; 


    const { data, error } = await supabase
        .from('ordini')
        .insert([
            { 
                id: idOrdineCasuale, 
                frullato: idFrullato 
            }
        ])
        .select(); 

    if (error) {
        console.error(error);
        return res.status(500).json({ error: "Errore durante l'ordine" }); 
    }

    
    res.status(201).json({ 
        message: "Ordine effettuato con successo!", 
        ordine: data[0] 
    });
});


//SESSIONI

const session = require('express-session'); 
const pgSession = require('connect-pg-simple')(session); 
const { Pool } = require('pg');

const pgPool = new Pool({
  connectionString: "postgres://postgres:Z1Yk8CHwXMBMQNTD@db.iblnubgcuixwisofranz.supabase.co:5432/postgres"
});

//setup della gestione delle sessioni
app.use(session({
  store: new pgSession({
    pool: pgPool,
    tableName: 'session'  //qui è importante specificare il nome giusto
  }),
  secret: 'una_stringa_segreta_molto_lunga', 
  resave: false,
  saveUninitialized: false,
  cookie: { 
    maxAge: 1000 * 60 * 60 * 24, //impostiamo la durata del cookie pari a 24 ore
    httpOnly: true //per non far leggere il cookie nel client (sicurezza)
  }
}));


//AUTENTICAZIONE
app.use(express.json()); //consente agli handler di leggere il body (renza questa riga la funzione req.body da errore)

/*

Use serve per creare un middleware, un ulteriore operazione che la richiesta subisce prima di raggiungere destinazione. 

IMPORTANTE: use applica un middleware a tutte le richieste in entrata.

IMPORTANTE: l'ordine in cui i middleware sono scritti nel mio file, sarebbe lo stesso con cui vengono applicati (app.use(espress.static(ROOT)) viene applicato prima di app.use(express.json()) )

IMPORTANTE: è necessario che certi middleware vengano scritti prima di alcine handler (esempio app.use(express.json()) deve essere scritto prima di req.body negli handler)


*/





const bcrypt = require('bcrypt') //usiamo bcrypt per fare un hashing della password


app.get('/api/me', (req, res) => {

    //req.session.user ritorna la sessione per l'utente se è presente
    if (req.session.user) {
        
        //se c'è una sessione attiva allora ritorno all'utente i suoi dati
        res.json(req.session.user);
    } else {
        //se non c'è una sessione, mando il codice 401 (non autorizzato)
        res.status(401).json({ error: "Non sei loggato" });
    }
});

app.post("/api/login", async (req,res) =>{
    const {email, password} = req.body; //anche qui passo i dati utente tramite il body

    //console.log("ricevuti: " + email + ", " + password)

    if (!email || !password) {
        return res.status(400).json({ error: "Tutti i campi sono obbligatori" });
    }

    //effettuo una select sul database per cercare l'utente
    const { data: user, error } = await supabase
        .from('utenti')
        .select('*')
        .eq('email', email) //lo cerchiamo rispetto alla mail
        .single();

    if (!user || error) {
        //401 -> utente non autorizzato
        return res.status(401).json({ error: "Utente non trovato" });
    }

    //a stringhe uguali corrispondono hash uguali
    const isPasswordCorrect = await bcrypt.compare(password, user.password_hash);

    if(isPasswordCorrect){
        
        //faccio partire una sessione e anche qui salvo i dati utente di base
        req.session.user = { 
            id: user.id, 
            username: user.username, 
            email: user.email 
        };

        res.json({ message: "Login effettuato!", user: req.session.user});
    } else {
        res.status(401).json({ error: "Password errata" });
    }

})



app.post("/api/register", async (req, res) =>{
    const {username, email, password} = req.body;  //richiediamo il body dalla richiesta (il body contiene i dati utente)

    //console.log("ricevuti: " + username +", "+ email +", " + password)

    if (!username || !email || !password) {
        return res.status(400).json({ error: "Tutti i campi sono obbligatori" });
    }

    //rifaccio il controllo sulla password (questo è un controllo forte, il server non è alterabile)
    if (password.length < 8) {
        return res.status(400).json({ error: "La password deve avere almeno 8 caratteri" });
    }

    try {
        
        //uso il sale nella funzione di hashing
        const saltRounds = 10;
        const hash = await bcrypt.hash(password, saltRounds);

        
        const { data, error } = await supabase
            .from('utenti')
            .insert([
                { 
                    username: username, 
                    email: email, 
                    password_hash: hash //noi inseriamo nel database l'hashing della password
                }
            ])
            .select();

        
        //quando il vincolo di chiave sulla mail è stato violato, allora postrgre restituisce il codice di errore 23505 IMPORTANTE: se non usate postgresql c'è un altro codice di errore
        if (error) {
            if (error.code === '23505') { //se la mail è in uso, notifico l'utente con un codice 400
                return res.status(400).json({ error: "Questa email è già registrata" });
            }
            throw error;
        }

        //faccio partire una nuova sessione e riempio il campo "sess" con i dati utente di base
        req.session.user = { 
            id: data[0].id, 
            username: data[0].username, 
            email: data[0].email 
        };

       
        res.status(201).json({ 
            message: "Utente creato con successo!",
            user: req.session.user //mandiamo i dati all'utente (non serve in realtà)
        });

    } catch (err) {
        console.error("Errore registrazione:", err);
        res.status(500).json({ error: "Errore interno del server" });
    }

})

app.post('/api/logout', (req, res) => {
    
    //uso la funzione destroy per cancellare la entry dalla tabella sessione e il cookie dal client
    req.session.destroy((err) => {
        if (err) {
            console.error("Errore durante il logout:", err);
            return res.status(500).json({ error: "Impossibile effettuare il logout" });
        }

        
        res.clearCookie('connect.sid'); 
        
        
        res.json({ message: "Logout effettuato con successo" });
    });
});

/*
PROBLEMA: non voglio che l'utente acceda alla pagina di login /registrazione se ha una sessione attiva

SOLUZIONE: creo un middleware solo per quelle URL e il middleware controlla se c'è la sessione

passando una funzione come parametro a get, tale funzione farà da middleware per quell'handler

l'oggetto next consente alla richiesta di attraversare il middleware e raggiungere destinazione

*/


const redirectIfLoggedIn = (req, res, next) => {
    //se c'è una sessione, rimanda l'utente alla pagina principale
    if (req.session.user) {
        return res.redirect('/'); 
    }
    
    //se non c'è la sessione permettiamo alla chiamata di raggiungere destinazione e quindi all'utente verrà ritornata la pagina di login
    next();
};


//Login 
app.get("/accedi/login", redirectIfLoggedIn, (req, res)=>{
    res.sendFile(path.join(ROOT, 'auth','login','index.html'))
})

//Registrazione
app.get("/accedi/registrazione", redirectIfLoggedIn, (req, res)=>{
    res.sendFile(path.join(ROOT, 'auth','registrazione','index.html'))
})



//AVVIO 
app.listen(PORT, HOST, ()=>{
    console.log(`server in esecuzione su http://localhost:${PORT}`)
})





