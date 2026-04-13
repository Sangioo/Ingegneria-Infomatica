<script setup>
import Header from '@/components/Header.vue'

/*
Un componente vue è formato da:
- script -> codice js 
- template -> codice html, definisce l'aspetto del componente
- style -> codice css, per lo stile del componente 

*/

/*
- App.vue sarebbe il componente padre, i componenti sono disposti in una gerarchia ad albero (in modo simile al DOM) e App.vue sarebbe la radice di quest'albero (funge da cornice per tutto il sito)

- App.vue definisce il layout del sito. Il layout di un sito è come scelgo di disporre quegli elementi del sito che non variano mai rispetto alle pagine. Il più comune è Header in alto poi body e footer.

*/
</script>

<template>
  <!-- Qui uso il componente header per piazzare l'header in ogni pagina del sito-->
  <Header />

  <main>
    <!-- RouterView è un componente speciale che raccoglie tutte le pagine del nostro sito e gestisce la loro navigazione-->
    <RouterView />
  </main>
</template>

<style scoped></style>
