<script setup>
const testo = 'ciao ragazzi'
const stili = 'bg-danger'
const condizione = true
const array = [1, 2, 3, 4, 5, 6]
const saluta = () => {
  alert('Ciao!')
}
</script>

<template>
  <div class="container">
    <!-- usando le doppie parentesi graffe possiamo assegnare del testo in html secondo una variabile-->
    <h1>{{ testo }}</h1>
    <br />

    <!-- v-bind mi consente di assegnare il valore di un attributo di un componente html tramite una variabile
     
    v-bind ammette la seguente sintassi: v-bind:class="[nome variabile]"

    ammette la seguente abbreviazione :class="[nome variabile]"
    -->
    <div v-bind:class="stili">Ciao Ragazzi</div>
    <div :class="stili">Ciao Ragazzi</div>
    <br />

    <!--
      v-if consente di renderizzare un componente se una certa condizione booleana è rispettata

      v-if ha la seguente sintassi v-if="[condizione]"
    -->
    <h2 v-if="condizione">Mostra solo se condizione è vera</h2>
    <h2 v-if="!condizione">Mostra solo se condizione è falsa</h2>
    <br />

    <!--
      v-for prende come input un iteratore e genera l'elemento html a cui è stato assegnato tante volte quante sono le iterazioni

      v-for ammette la seguente sintassi: v-for="[iteratore]"

      Quando usiamo v-for è necessario assegnare la chiave (attributo key) degli elementi html generati.In questo caso usiamo la variabile del ciclo (i) per:
        - assegnare la chiave 
        - assegnare il testo
    -->

    <div v-for="i in array" :key="i" class="bg-secondary">
      <h3>Contenitore numero {{ i }}</h3>
    </div>
    <br />

    <!--
    v-on server per ascoltare eventi provenienti da un determinato elemento html (su cui v-on è assegnato) e di invocare una funzione quando l'evento viene ascolato

    v-on ha la seguente sintassi v-on:[nome evento]="[funzione da invocare]"

    v-on può essere abbreviato con @
    -->

    <div class="btn btn-secondary" v-on:click="saluta">Saluta</div>
    <br />
    <br />
    <div class="btn btn-success" @:click="saluta">Saluta</div>
  </div>
</template>
