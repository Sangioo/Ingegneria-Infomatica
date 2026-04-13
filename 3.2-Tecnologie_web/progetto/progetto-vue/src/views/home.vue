<script setup></script>

<template>
  <div id="container">
    <main class="hero-section">
      <div class="container text-center">
        <h1>FrameLog</h1>
        <p>Il diario dei tuoi film preferiti</p>
        Per cominciare <a class="link-underline link-underline-opacity-0" href="/login">accedi</a> o
        <a class="link-underline link-underline-opacity-0" href="/register">registrati</a>.
      </div>
    </main>
  </div>
</template>

<style scoped>

* {
  box-sizing: border-box;
}

#container {
  margin: 0;
  min-height: 100vh;
  background: radial-gradient(circle at top, #ffffff, var(--alabaster-grey));
  color: var(--evergreen);
  font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
}

.hero-section {
  min-height: calc(100vh - 72px);
  display: grid;
  place-items: center;
  padding: 2rem 1rem;
}

h1 {
  margin: 0 0 0.75rem;
  font-size: clamp(2rem, 6vw, 3.2rem);
}

p {
  margin: 0;
  font-size: clamp(1rem, 2.8vw, 1.3rem);
  color: var(--deep-teal);
  font-weight: 600;
}

a {
  color: var(--deep-teal);
  font-weight: 700;
}

a:hover {
  color: var(--mint-leaf);
}
</style>
