CREATE TABLE public.movies (
  id bigint GENERATED ALWAYS AS IDENTITY NOT NULL,
  title text NOT NULL DEFAULT ''::text,
  original_language text,
  original_title text DEFAULT ''::text,
  overview text DEFAULT ''::text,
  poster_path text,
  release_date date,
  genre_ids json,
  backdrop_path text,
  vote_average real,
  CONSTRAINT movies_pkey PRIMARY KEY (id)
);
CREATE TABLE public.users (
  id uuid NOT NULL,
  email text NOT NULL,
  username text,
  profile_pic_url text,
  CONSTRAINT users_pkey PRIMARY KEY (id),
  CONSTRAINT users_new_id_fkey FOREIGN KEY (id) REFERENCES auth.users(id)
);
CREATE TABLE public.reviews (
  user uuid NOT NULL,
  movie bigint NOT NULL,
  content text NOT NULL DEFAULT ''::text,
  score smallint NOT NULL,
  time timestamp with time zone NOT NULL DEFAULT now(),
  CONSTRAINT reviews_pkey PRIMARY KEY (user, movie),
  CONSTRAINT reviews_new_user_fkey FOREIGN KEY (user) REFERENCES public.users(id),
  CONSTRAINT reviews_new_movie_fkey FOREIGN KEY (movie) REFERENCES public.movies(id)
);
CREATE TABLE public.watch (
  user uuid NOT NULL DEFAULT gen_random_uuid(),
  movie bigint NOT NULL,
  watched boolean NOT NULL DEFAULT false,
  CONSTRAINT watch_pkey PRIMARY KEY (user, movie),
  CONSTRAINT watch_new_movie_fkey FOREIGN KEY (movie) REFERENCES public.movies(id),
  CONSTRAINT watch_new_user_fkey FOREIGN KEY (user) REFERENCES public.users(id)
);
CREATE TABLE public.rooms (
  movie bigint NOT NULL,
  user uuid NOT NULL,
  CONSTRAINT rooms_pkey PRIMARY KEY (user, movie),
  CONSTRAINT rooms_new_user_fkey FOREIGN KEY (user) REFERENCES public.users(id),
  CONSTRAINT rooms_new_movie_fkey FOREIGN KEY (movie) REFERENCES public.movies(id)
);
