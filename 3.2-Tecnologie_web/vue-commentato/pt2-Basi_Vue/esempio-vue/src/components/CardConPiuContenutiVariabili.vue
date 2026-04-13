<script setup></script>

<template>
  <div class="bg-secondary rounded col-4 p-2">
    <!-- posso usare name per assegnare dei nomi agli slot-->
    <slot name="slot1"> </slot>
    Componente con più contenturi variabili
    <slot name="slot2"> </slot>
  </div>
</template>
