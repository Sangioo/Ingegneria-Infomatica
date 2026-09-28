
//Public = contiene tutti i file del front end da inviare al client
//Server = contiene i file del server


const express = require('express') //importiamo express
const app = express() //app è un oggetto con cui poi chiamiamo alcuni metodi


const PORT = 3000 //Imposto la prota 
const HOST = '0.0.0.0' //Per consentire accesso da tutti i dispositivi nella rete locale


//IMPOSTIAMO LE ROTTE
const path = require("path") //importiamo path, serve per gestire le directory nel file system in modo univoco per ogni sistema operativo
const ROOT = path.join(__dirname,'..','public') //join serve per unire delle directory in modo univoco per ogni sistema operativo, __dirname sarebbe la directory del file attuale, salviamo una varibile ROOT che punta ai file del front end
app.use(express.static(ROOT));  //use collega i file all'interno di una rotta (INCLUDETELA SENNO CSS NON FUNZIONA)



//NAVIGAZIONE 

/*
Il metodo get serve per registrare un handler (una funzione) corrispondente ad una chiatama http di GET, in particolare prende due campi:
    - la URL della chiamata HTTP (ad esempio "/" per la home)
    - l'handler, la funzione da eseguire quando la chiamata arriva

Al momento dell'esecuzione di get non succede nulla, ciò che node.js fa è semplicemente salvare l'hadler e associarlo alla chiamata, in questo modo quando una chiamata arriva:
    - node.js controlla se è stato registrato un handler per quella chiamata.
    - prende i parametri della chiamata e istanzia due oggetti che vanno passati come input all'handler, essi sono:
        - req: serve per accedere ai campi passati in input alla richiesta
        - res: serve per aprire un canale di comunicazione in uscita verso il client.
    
Nota: è una convenzione che si chiamino req e res, potete chiamarli come volete.
Nota: in JS siccome non abbiamo i tipi "diamo per scontato" che questi due oggetti abbiano metodi come ad esempio sendFile

*/

//Pagina home
app.get('/',(req,res)=>{
    res.sendFile(path.join(ROOT,'index.html')) //sendFile serve a inviare un file al client, in questo caso html
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



//QUERY SU DATABASE
//Queste righe sono di setup, dipendono dal vostro servizio di DB
const {createClient} = require("@supabase/supabase-js")
const supabaseApi = 'https://iblnubgcuixwisofranz.supabase.co' 
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
        `) //effetuaimo la query sul DB, questa sintassi dipende dal DB che usate
    
    //uso await per aspettare che la query finisca
    if(error){
        res.send(500).json({error: 'An error occured while fetching data'}) //usiamo la funzione send per inviare uno stato di errore al client e un JSON contenente il messaggio di errore.
        return
    }

    //se non ci sono stati errori, usiamo la funzione JSON per inviare i dati estratti dal DB in formato json
    res.json(data) 
    
})

/*
In HTTP abbiamo i seguenti codici associati ad uno stato:
    - 500 (quelli che cominciano con 5): errore del server, ad esempio una query sul DB fallita
    - 400 (quelli che cominciano con 4): cattiva richiesta del client, ad esempio 404 page not found
    - 200: successo
*/

/*
Una funzione asincrona si dichiara tramite il costrutto async, in poche parole è una funzione che non so quanto impiegherà ad eseguire. 
Una funzione asincrona non ritorna un oggetto ma ritorna un oggetto speciale chiamato promessa, la promessa può avere tre stati:
    - pending: la funzione che l'ha ritornata sta ancora eseguendo, quindi il suo valore di ritorno non è ancora disponibile.
    - resolved: la funzione che l'ha ritornata ha terminato con successo l'esecuzione, quindi il suo valore di ritorno è pronto.
    - rejected: la funzione che l'ha ritornata ha terminato con uno stato di errore, quindi il suo valore di ritorno non è disponibile, ma sarà disponibile il codice dell'errore.

Una funzione asincrona può essere invocata in due modi:
    - tramite il costrutto await: sia la funzione C che chiama D, se D è asincrona e C invoca D tramite await allora C bloccherà il suo flusso di esecuzione al momento della chiamata. C quindi attende che la promessa che ha ritornato D passi dallo stato pending agli stati resolved o reject. 

    Quando C chiama D tramite await (D è asincrona) anche C diventa asincrona. Quando ciò succede il compilatore ci obbliga infatti a dichiara C tramite async.

    C = () => {
        instr. 1
        instr. 2
        await D() -> C blocca il flusso fino a che D non ha finito, abbiamo un errore se non dichiariamo C asincrona: C = async () => {...}
        instr. 3
        ...    
    }
    Nota: in questo modo se D ritorna dei valori che mi servono in operazioni immediatamente successive (es. instr. 3) non c'è nessun problema perché essi sono disponibili (a meno che non ci sia stato un errore)
    Nota: dal punto di vista del programmatore è come usare una funzione "normale".

    - senza await: in tal caso C non blocca il flusso di esecuzione ma continua ad eseguire le operazioni dopo D (non aspetta che la promessa ritornata da D esca dallo stato pending). Questo significa che se dopo la chiamata a D c'è un'operazione che richieda il dato da D ritornato, tale dato potrebbe non essere disponibile.

    C = () => {
        instr. 1
        instr. 2
        oggetto = D() -> non aspettiamo che D finisca ma andiamo avanti 
        console.log(oggetto)  -> se oggetto non è disponibile allora esso non viene stampato, ma viene stampato un oggetto di tipo promessa allo stato pending.
    }
    Nota: questo è vantaggioso se voglio chiamare tante funzioni asincrone allo stesso momento (ovviamente esse non devono dipendere l'una dall'altra).
    Nota: alcuni linguaggi danno un warning se non usate await (C# ad esempio).


*/

//il metodo post fa la stessa cosa del metodo get, ma solo per chiamate POST
// i due punti (:id) servono a indicare un parametro variabile (utile per passare dati)
app.post('/api/ordina-frullato/:id', async (req, res) => {
    const idFrullato = req.params.id; //usiamo req per recuperare il codice del frullato (il parametro variabile di cui parlavamo)

    const idOrdineCasuale = Math.floor(Math.random() * 9000) + 1000; //un numero casuale come id dell'ordine 



    const { data, error } = await supabase
        .from('ordini')
        .insert([
            { 
                id: idOrdineCasuale, 
                frullato: idFrullato 
            }
        ])
        .select(); //select serve a ritornare la riga inserita nel database
        //anche qui usiamo await per aspettare che la query abbia finito

    if (error) {
        console.error(error);
        return res.status(500).json({ error: "Errore durante l'ordine" });
    }

    //201 è un codice di successo
    //mandiamo anche un JSON contente un messaggio testuale di successo e la riga inserita nel DB
    res.status(201).json({ 
        message: "Ordine effettuato con successo!", 
        ordine: data[0] 
    });
});


//AVVIO 
app.listen(PORT, HOST, ()=>{
    console.log(`server in esecuzione su http://localhost:${PORT}`)
})

/* 
tramite la funzione listen il server si mette in ascolto su una porta, essa prende come parametri:
    - una porta
    - l'host (opzionale)
    - una funzione, che ha scopi di log. 

Quando eseguiamo listen:
    - node.js esegue la funzione che abbiamo passato.
    - entra in una stato di loop infinito durante il quale ascolta sulla porta per eventuali chiamate HTTP. Quando una chiamata arriva, node.js controlla se è stato registrato un handler per quella chiamata (tramite get e post) e poi viene eseguito quell'handler. IMPORTANTE: listen va eseguita alla fine, dopo tutti i get e post
*/

/*
GET: richiediamo dati dal DB
POST: inseriamo dati dal DB
DELETE: rimuoviamo dati dal DB
PUT/PATCH: la modifica di dati già esistenti del DB
*/

/*
due modi:
    - usi un servizio che lo faccia da solo:
        VANTAGGIO: è semplice
        SVANTAGGIO: il setup iniziale potrebbe essere complicato e non sai cosa succede dietro le quinte.
    - creare una tabella sessione e salvare dentro questa tabella un id_sessione e un id_utente, poi dovresti, dopo che l'utente si è loggato, caricare un cookie con l'id_sessione. Ad ogni accesso succesivo se il cookie è ancora valido fai una query sulla tabella e guardi se è presente una sessione per quell'utente. 
        VANTAGGIO: sai cosa fai
        SVANTAGGIO: è complicato

*/



