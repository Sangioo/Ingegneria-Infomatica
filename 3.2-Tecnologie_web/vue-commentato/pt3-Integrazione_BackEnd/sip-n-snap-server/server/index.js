
const express = require('express')

const app = express()

const PORT = 3000
const HOST = '0.0.0.0'  





//Navigazione
const path = require("path")
const ROOT = path.join(__dirname,'..','dist') 

app.use(express.static(ROOT));

//Pagina home
// app.get('/',(req,res)=>{
//     res.sendFile(path.join(ROOT,'index.html'))
// })



// //Chi siamo
// app.get("/chi-siamo",(req,res)=>{
//     res.sendFile(path.join(ROOT,'chi-siamo','index.html'))
// })


// //Contatti
// app.get("/contatti",(req,res)=>{
//     res.sendFile(path.join(ROOT,'contatti','index.html'))
// })

// //Ordina
// app.get("/ordina",(req,res)=>{
//     res.sendFile(path.join(ROOT,'ordina','index.html'))
// })


//QUERY SU DATABASE

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

    // Eseguiamo l'inserimento su Supabase
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

//Aggiungiamo questo middleware
app.use((req, res) => {
    res.sendFile(path.join(ROOT, 'index.html'));
});



app.listen(PORT, HOST, ()=>{
    console.log(`server in esecuzione su http://localhost:${PORT}`)
})
