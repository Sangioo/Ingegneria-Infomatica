<script setup>
//Qui è dove importeremo altri componenti

import Header from '@/components/Header.vue'
import Footer from './components/Footer.vue'
</script>
<!-- definiamo un classico layout header, main, footer-->
<template>
  <Header />

  <main class="flex-grow-1">
    <RouterView />
  </main>

  <Footer />
</template>

<style></style>
