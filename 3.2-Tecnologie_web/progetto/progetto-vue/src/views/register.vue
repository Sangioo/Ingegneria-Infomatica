<script setup></script>

<template>
  <div id="container">
    <main class="auth-section">
      <section class="auth-card">
        <h1 class="auth-title mb-2">Crea il tuo account</h1>
        <p class="auth-subtitle mb-4">Inizia a tenere traccia dei film che ami.</p>

        <form action="/register" method="post" class="d-grid gap-3">
          <div>
            <label for="username" class="form-label">Username</label>
            <input
              type="text"
              class="form-control"
              id="username"
              name="username"
              placeholder="es. andrea"
              required
            />
          </div>

          <div>
            <label for="email" class="form-label">Email</label>
            <input
              type="email"
              class="form-control"
              id="email"
              name="email"
              placeholder="nome@email.com"
              required
            />
          </div>

          <div>
            <label for="password" class="form-label">Password</label>
            <input
              type="password"
              class="form-control"
              id="password"
              name="password"
              placeholder="Almeno 8 caratteri"
              required
            />
          </div>

          <button class="btn btn-primary mt-2" type="submit">Registrati</button>
        </form>

        <p class="auth-extra mb-0 mt-3">Hai gia un account? <a href="/login">Accedi</a></p>
      </section>
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
  background: radial-gradient(circle at top, white, var(--alabaster-grey));
  color: var(--evergreen);
  font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
}

.auth-section {
  min-height: calc(100vh - 72px);
  display: grid;
  place-items: center;
  padding: 2rem 1rem;
}

.auth-card {
  width: min(440px, 100%);
  background: white;
  border: 1px solid var(--muted-teal);
  border-radius: 1rem;
  box-shadow: 0 14px 32px rgba(94, 128, 127, 0.15);
  padding: 2rem;
}

.auth-title {
  margin: 0;
  font-size: clamp(1.5rem, 3vw, 2rem);
}

.auth-subtitle {
  margin: 0;
  color: var(--deep-teal);
  font-size: 1rem;
  font-weight: 600;
}

.form-label {
  color: var(--evergreen);
  font-weight: 600;
}

.form-control {
  border-color: var(--muted-teal);
}

.form-control:focus {
  border-color: var(--mint-leaf);
  box-shadow: 0 0 0 0.25rem rgba(23, 184, 144, 0.2);
}

.btn-primary {
  background-color: var(--mint-leaf) !important;
  border-color: var(--mint-leaf) !important;
  color: white !important;
}

.btn-primary:hover,
.btn-primary:focus {
  background-color: var(--deep-teal) !important;
  border-color: var(--deep-teal) !important;
}

.auth-extra {
  color: var(--evergreen);
}

.auth-extra a {
  color: var(--deep-teal);
  font-weight: 600;
  text-decoration: none;
}

.auth-extra a:hover {
  text-decoration: underline;
}

@media (max-width: 576px) {
  .auth-card {
    padding: 1.5rem;
  }
}
</style>
