<script setup></script>

<template>
  <footer class="footer py-4 mt-auto">
    <div class="container">
      <div class="row align-items-center gy-3">
        <div class="col-12 col-md">
          <a href="/" class="footer-brand text-decoration-none fs-4 fw-semibold">FrameLog</a>
          <p class="footer-note mb-0 mt-1">Il tuo spazio per raccontare il cinema.</p>
        </div>

        <div class="col-12 col-md-auto">
          <ul class="nav gap-1 justify-content-md-end">
            <li class="nav-item">
              <a href="/" class="footer-link nav-link px-2">Home</a>
            </li>
            <li class="nav-item">
              <a href="/profile" class="footer-link nav-link px-2">Profile</a>
            </li>
            <li class="nav-item">
              <a href="/about-us" class="footer-link nav-link px-2">About Us</a>
            </li>
            <li class="nav-item">
              <a href="/contacts" class="footer-link nav-link px-2">Contacts</a>
            </li>
          </ul>
        </div>
      </div>
    </div>
  </footer>
</template>

<style scoped>
.footer {
  background-color: var(--evergreen);
  border-top: 4px solid var(--mint-leaf);
}

.footer-brand {
  color: var(--alabaster-grey);
}

.footer-note {
  color: var(--muted-teal);
}

.footer-link,
.footer-link:visited {
  color: var(--alabaster-grey) !important;
  font-weight: 500;
}

.footer-link:hover,
.footer-link:focus {
  color: var(--mint-leaf) !important;
}
</style>
