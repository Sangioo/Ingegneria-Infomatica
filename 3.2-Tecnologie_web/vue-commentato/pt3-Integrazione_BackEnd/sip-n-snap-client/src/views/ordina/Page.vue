<script setup>
import { ref, onMounted } from 'vue'
import MenuCard from '@/components/MenuCard.vue'

/*
usiamo ref per due variabili dinamiche:
- un array di frullati 
- un codice di errore
*/
const listaFrullati = ref([])
const errore = ref(null)

// LOGICA: Caricamento dati
const caricaFrullati = async () => {
  try {
    const response = await fetch('/api/frullati')
    if (!response.ok) throw new Error('Errore nel caricamento')

    listaFrullati.value = await response.json()
  } catch (err) {
    errore.value = err.message
    console.error(err)
  }
}

const inviaOrdine = async (idFrullato) => {
  try {
    const response = await fetch(`/api/ordina-frullato/${idFrullato}`, {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
    })

    if (!response.ok) throw new Error("Impossibile completare l'ordine")

    const risultato = await response.json()
    alert(`Grazie! Ordine n° ${risultato.ordine.id} ricevuto.`)
  } catch (err) {
    alert(err.message)
  }
}
//usiamo onMounted per fare la chiamata al database quando il componente viene renderizzato all'utente
onMounted(caricaFrullati)
</script>

<template>
  <main class="container my-5 flex-grow-1">
    <!-- usiamo v-if per far apparire il codice di errore se l'oggetto errore non è null-->
    <div v-if="errore" class="alert alert-danger">{{ errore }}</div>

    <!-- usiamo v-for per generare tante card quanti frullati-->
    <div class="row g-4">
      <!-- usiamo v-on per rilevare l'evento 'ordina' e invocare la chiamata API per effetuare l'ordine (la funzione inviaOrdine)-->
      <MenuCard v-for="f in listaFrullati" :key="f.id" :frullato="f" @ordina="inviaOrdine" />
    </div>

    <!-- usando v-if mostro un testo che informa l'utente dello stato di caricamente in caso la lista dei frullati sia nulla-->
    <div v-if="listaFrullati.length === 0 && !errore" class="text-center">
      Caricamento frullati...
    </div>
  </main>
</template>
