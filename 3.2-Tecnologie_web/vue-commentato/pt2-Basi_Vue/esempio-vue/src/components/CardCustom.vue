<script setup>
defineProps({
    oggetto: {
        type: Object,
        required: true
    }
})
</script>
<template>
    <div class="card" style="width: 18rem">
        <div class="card-body">
            <h5 class="card-title">{{ oggetto.titolo }}</h5>
            <p class="card-text">{{ oggetto.testo }}</p>
        </div>
    </div>
</template>
<style scoped></style>