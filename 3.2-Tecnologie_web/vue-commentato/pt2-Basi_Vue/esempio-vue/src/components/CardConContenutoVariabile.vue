<script setup></script>

<template>
  <div class="bg-secondary rounded col-4 p-2">
    Componente con contentuto variabile
    <!-- l'elemento slot può essere riempito dal componente padre con elementi html a piacimento-->
    <slot>
      <!-- se noi inseriamo degli elementi html dentro slot allora essi verrano mostrati come contenuti di default se il padre non riempie lo slot-->
      <div class="col-12 bg-success rounded p-2">Contenuto di Default</div>
    </slot>
  </div>
</template>
