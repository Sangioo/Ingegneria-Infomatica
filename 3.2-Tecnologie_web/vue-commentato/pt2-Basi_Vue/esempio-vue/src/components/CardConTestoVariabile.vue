<script setup>
/*
tramite defineProps definiamo una prop, una prop è un attributo per il mio componente, chi invoca il mio componente può decidere cosa passare ad esso
*/
defineProps({
  titoloDellaCard: String,
})
</script>

<template>
  <div class="bg-secondary rounded col-4">{{ titoloDellaCard }}</div>
</template>
