import { createApp } from 'vue'
import App from './App.vue'
import router from './router'
import '@/styles/bootstrap.css' //se volete importare file css esterni potete farlo qui

const app = createApp(App)

app.use(router)

app.mount('#app')

/*
Quattro file pregenerati:
main.js -> setup di vue (assembla il front-end)
App.vue -> definisce un layout del sito
index.html -> sarebbe proprio il file "vuoto" che mandiamo al client e poi viene usato per assemblare tutte le pagine
router/index.js -> definisce la navigazione 

- Server Side Rendering (SSR): ogni volta che il client richiede una nuova pagina è necessaria una nuova chiamata GET al server e il server risponde con un file html (per quella pagina)
    - questo era l'approccio della scorsa lezione (node.js)

- Client Side Rendering (CSR): la prima volta che il client apre il sito il server manda già tutte le pagine, però queste pagine non sono file html completi. Ma il server manda un file html vuoto assieme ad un file javascript che viene eseguito nel client e che assembla il front-end (con tutte le pagine)
    - l'approccio che seguiamo con vue
    - dopo di che il client non manda più richieste per pagine, il client gestisce una navigazione interna (in questo caso tramite router/index.js)

*/
