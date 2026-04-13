<script setup>
import CardConTestoFisso from '@/components/CardConTestoFisso.vue'
import CardConTestoVariabile from '@/components/CardConTestoVariabile.vue'
import CardConContenutoVariabile from '@/components/CardConContenutoVariabile.vue'
import CardConPiuContenutiVariabili from '@/components/CardConPiuContenutiVariabili.vue'
import CardConBottone from '@/components/CardConBottone.vue'

const messaggioAllUtente = (messaggio) => {
  alert(messaggio)
}

/*
- prop
- slot
- emit
*/
</script>

<template>
  <div class="container">
    <!-- componente statico, che io non "personalizzo"-->
    <CardConTestoFisso />
    <br />

    <!-- assegno il valore alla prop titolo-della-card come se fosse un attributo di un elemento html-->
    <CardConTestoVariabile titolo-della-card="Testo scelto da me" />
    <br />

    <CardConContenutoVariabile>
      <div class="bg-primary rounded col-12 p-1">Contenuto a Piacere</div>
    </CardConContenutoVariabile>
    <br />

    <CardConContenutoVariabile> </CardConContenutoVariabile>
    <br />

    <CardConPiuContenutiVariabili>
      <!-- devo usare l'elemento template e con # indico lo slot che voglio riempire-->
      <template #slot1>
        <div class="bg-danger rounded col-12 p-1">Ciao Ragazzi</div>
      </template>
      <template #slot2>
        <div class="bg-warning rounded col-12 p-1">Ciao Ragazzi</div>
      </template>
    </CardConPiuContenutiVariabili>
    <br />

    <!-- usiamo v-on per catturare l'evento 'saluta' e invocare messaggioAllUtente con input pari al payload di saluta-->
    <CardConBottone v-on:saluta="messaggioAllUtente" />
  </div>
</template>
