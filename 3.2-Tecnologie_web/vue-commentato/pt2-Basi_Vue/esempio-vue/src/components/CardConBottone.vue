<script setup>
const emit = defineEmits(['saluta'])
/*
la funzione emit mi consente di definire eventi che un componente può lanciare verso il componente padre.

In questo caso io definisco un nuovo evento e lo chiamo saluta
*/
</script>
<template>
  <div class="bg-secondary rounded col-4 p-2">
    <!-- emit prende due parametri:
      - l'evento da lanciare (lancio l'evento 'saluta')
      - il payload da mandare assieme all'evento (mando la stringa 'messaggio da inviare')
    -->
    <div class="btn btn-secondary" v-on:click="emit('saluta', 'messaggio da inviare')">Saluta</div>
  </div>
</template>
