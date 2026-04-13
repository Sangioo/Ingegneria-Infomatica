<script setup></script>
<template>
  <nav class="navbar navbar-expand-lg alabaster-grey-white border-bottom shadow-sm">
    <div class="container">
      <a class="navbar-brand" href="#">
        <img src="@/img/logo.svg" alt="FrameLog" width="30" height="30" />
      </a>
      <a class="navbar-brand fw-bold" href="/">FrameLog</a>
      <button
        class="navbar-toggler"
        type="button"
        data-bs-toggle="collapse"
        data-bs-target="#mainNavbar"
        aria-controls="mainNavbar"
        aria-expanded="false"
        aria-label="Toggle navigation"
      >
        <span class="navbar-toggler-icon"></span>
      </button>

      <div class="collapse navbar-collapse" id="mainNavbar">
        <ul class="navbar-nav me-auto mb-2 mb-lg-0">
          <li class="nav-item">
            <a class="nav-link active" aria-current="page" href="/">Home</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="/watchlist">Watchlist</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="/watched">Watched</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="/profile">Profile</a>
          </li>
        </ul>
        <div class="d-flex gap-2">
          <a class="btn btn-outline-secondary btn-sm" href="/login">Login</a>
          <a class="btn btn-primary btn-sm" href="/register">Register</a>
        </div>
      </div>
    </div>
  </nav>
</template>
<style scoped>

* {
  box-sizing: border-box;
}

.navbar.alabaster-grey-white {
  background: var(--alabaster-grey) !important;
  border-bottom-color: var(--muted-teal) !important;
}

.navbar-brand,
.nav-link {
  color: var(--evergreen) !important;
}

.nav-link.active,
.nav-link:hover {
  color: var(--deep-teal) !important;
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

.btn-outline-secondary {
  color: var(--deep-teal) !important;
  border-color: var(--deep-teal) !important;
}

.btn-outline-secondary:hover,
.btn-outline-secondary:focus {
  background-color: var(--deep-teal) !important;
  border-color: var(--deep-teal) !important;
  color: white !important;
}
</style>