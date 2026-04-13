import { createRouter, createWebHistory } from 'vue-router'
import Home from '@/views/Page.vue'
import Logica from '@/views/logica/Page.vue'
import Template from '@/views/template/Page.vue'
import Mattoncini from '@/views/mattoncini/Page.vue'

/*
Ogni pagina del sito è un componente vue. In questo file associo ogni URL a un determinato componente Vue

*/

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/',
      name: 'home',
      component: Home,
    },
    {
      path: '/logica',
      name: 'logica',
      component: Logica,
    },
    {
      path: '/mattoncini',
      name: 'mattoncini',
      component: Mattoncini,
    },
    {
      path: '/template',
      name: 'template',
      component: Template,
    },
  ],
})

export default router
