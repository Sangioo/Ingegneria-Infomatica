<script setup>
/*
definiamo una prop frullato
*/

defineProps({
  frullato: Object,
})

/*
definiamo un evento 'ordina'
*/

const emit = defineEmits(['ordina'])
</script>

<template>
  <div class="col-12 col-md-6 col-lg-4">
    <div class="bg-secondary p-2 d-flex flex-column rounded">
      <div class="d-flex">
        <img
          v-bind:src="frullato.img_path"
          alt=""
          class="col-4 object-fit-cover rounded"
          style="aspect-ratio: 1"
        />
        <div class="d-flex flex-column ms-2">
          <h3>{{ frullato.nome }}</h3>
          <p class="fs-3">{{ frullato.prezzo }}€</p>
          <span class="text-bg-info rounded-3 fs-6 me-auto px-2">
            {{ frullato.categorie.nome }}
          </span>
        </div>
      </div>

      <!-- con v-on rileviamo il click dell'utente sul bottone, e lanciamo l'evento ordina e mandiamo come payload l'id del frullato-->
      <button @click="emit('ordina', frullato.id)" class="btn btn-secondary mt-3 col-6">
        Ordina
      </button>
    </div>
  </div>
</template>
