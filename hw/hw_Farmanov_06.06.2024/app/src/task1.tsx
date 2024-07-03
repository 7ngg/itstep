import { useEffect, useState } from "react";
import OmdbService, { Movie } from "./Services/MovieService";

const Task1 = () => {
  const omdbService = new OmdbService("82130204");

  let [movies, setMovies] = useState<Movie[]>([]);

  useEffect(() => {
    const fetchMovies = async () => {
      try {
        const mvResponse = await omdbService.getData("Batman", "movie");
        setMovies(mvResponse);
      } catch (error) {
        console.error("Error fetching movies:", error);
      }
    };

    fetchMovies();
  }, []);

  return (
    <div className="grid grid-cols-3 gap-5 p-10 rounded-md">
      {movies.map((mv) => movieCard(mv))}
    </div>
  );
};

const movieCard = (card: Movie) => {
  return (
    <div className="flex gap-5 shadow">
      <div className="h-full">
        <img src={card.Poster} className="h-full object-contain" />
      </div>
      <div>
        <h1>{card.Title}</h1>
        <h2>{card.Year}</h2>
        <div className="flex flex-col">
          <h3>Schedule:</h3>
          {card.Schedule.map((s) => (
            <a className="hover:underline cursor-pointer">{s.toUTCString()}</a>
          ))}
        </div>
      </div>
    </div>
  );
};

export default Task1;
