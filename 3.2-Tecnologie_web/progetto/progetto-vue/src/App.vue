<script setup>
import Header from '@/components/header.vue'
import Footer from '@/components/footer.vue'
</script>

<template>
  <Header />
  <main>
    <router-view />
  </main>
  <Footer />
</template>

<style scoped></style>
