<script setup>
import { ref, computed, onMounted, onUnmounted } from 'vue'
/*

ref serve per creare quella che si chiava variabile reattiva, una variabile reattiva fa ricaricare l'intero componente quando essa cambia. Se il componente mostravata tale variabile esso si "aggiornerà" dopo il cambiamento di tale variabile.

ref prende in input il valore iniziale della variabile

IMPORTANTE: all'interno del codice javascript per accedere al valore di una variabile dinamica dobbiamo usare il suo attributo value ([nome variabile].value)
*/

const contatore = ref(0)

const contatorePerDieci = computed(() => {
  console.log('moltiplico per 10')
  return contatore.value * 10
})

/*
computed serve per creare una variabile dinamica, che viene aggiornata tramite una funzione che viene eseguita non appena una delle variabili dentro questa funzione non cambia
*/

let timer
const contoAttuale = ref(3)
const contoAllaRovescia = () => {
  timer = setTimeout(() => {
    contoAttuale.value--
    setTimeout(() => {
      contoAttuale.value--
      setTimeout(() => {
        contoAttuale.value--
      }, 1000)
    }, 1000)
  }, 1000)
}

/*
onMounted prende in input una funzione e la esegue quando il componente viene renderizzato all'utente

Di solito si usa per far partire una chiamata API non appena l'utente apre la pagina

*/

onMounted(contoAllaRovescia)

const fermaContoAllaRovescia = () => {
  clearInterval(timer)
  console.log('Timer pulito con successo')
}
/*
onUnmounted prende in input una funzione e la esegue quando il componente non viene più renderizzato.

Serve solitamente per fare dei cleanup di memoria. 

*/

onUnmounted(fermaContoAllaRovescia)
</script>

<template>
  <div class="container py-4">
    <div class="bg-secondary rounded p-3">
      <div class="d-flex">
        <div
          class="btn btn-success"
          @click="
            () => {
              contatore++
            }
          "
        >
          Aumenta
        </div>
        <div
          class="btn btn-success ms-3"
          @click="
            () => {
              contatore--
            }
          "
        >
          Diminuisci
        </div>
      </div>
      <br />
      <h2>Contatore: {{ contatore }}</h2>
      <h2>Contatore per dieci: {{ contatorePerDieci }}</h2>
    </div>
    <br />
    <div class="bg-secondary rounded p-3">
      <h2>Conto attuale: {{ contoAttuale }}</h2>
    </div>
  </div>
</template>
