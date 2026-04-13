import { createRouter, createWebHistory } from 'vue-router'
import Home from '@/views/Page.vue'
import Contatti from '@/views/contatti/Page.vue'
import ChiSiamo from '@/views/chi-siamo/Page.vue'
import Ordina from '@/views/ordina/Page.vue'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/',
      name: 'home',
      component: Home,
    },
    {
      path: '/contatti',
      name: 'contatti',
      component: Contatti,
    },
    {
      path: '/chi-siamo',
      name: 'chi siamo',
      component: ChiSiamo,
    },
    {
      path: '/ordina',
      name: 'ordina',
      component: Ordina,
    },
  ],
})

export default router
