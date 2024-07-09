import React from "react";
import { useRef, useState, useEffect } from "react";
import axios from "axios";

function Movies(props) {
  const [movies, setMovies] = useState();
  const [pages, setPages] = useState(1);
  const [currentPage, setCurrentPage] = useState(1);

  useEffect(() => {
    console.log(movies);
  }, [movies]);

  const searchInput = useRef();
  function getMoviesByName(page = 1) {
    console.log("Page number:", page);
    const options = {
      method: "GET",
      url: "https://api.themoviedb.org/3/search/movie",
      params: {
        query: searchInput.current.value,
        include_adult: "false",
        language: "en-US",
        page: page,
      },
      headers: {
        accept: "application/json",
        Authorization:
          "Bearer eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiI3N2EwNjE4MjM4MWM4Y2IzZWE2MGQ4YmFiMTJlMjAxZiIsIm5iZiI6MTcyMDU1MjcxNS4xMTEyNjksInN1YiI6IjY2OGQ4YWNhMGU2YTc2MDRlYjQ3NTc5NCIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.HWrCUAd8KyZwGGHTahb1xL7lkynY-7RKXAkEB-5qjjo",
      },
    };

    axios
      .request(options)
      .then(function (response) {
        console.log(response);
        setMovies(response.data.results);
        setPages(response.data.total_pages);
        setCurrentPage(page);
      })
      .catch(function (error) {
        console.error(error);
      });
  }

  return (
    <div className="flex flex-col items-center">
      <div className="flex justify-center items-center h-screen">
        <div className="flex flex-col w-96">
          <input
            ref={searchInput}
            type="text"
            placeholder="Search for movies"
            className="px-4 py-2 border border-gray-300 rounded-md"
          />
          <button
            onClick={() => getMoviesByName()}
            className="bg-blue-500 text-white px-4 py-2 mt-2 rounded-md"
          >
            Search
          </button>
        </div>
      </div>

      <div className="grid grid-cols-4 gap-4">
        {movies &&
          movies.map((movie) => (
            <div key={movie.id} className="bg-gray-200 p-4 rounded-md">
              <img
                src={`https://image.tmdb.org/t/p/w500/${movie.poster_path}`}
                alt={movie.title}
                className="rounded-md"
              />
              <h2 className="text-lg font-bold mt-2">{movie.title}</h2>
            </div>
          ))}
      </div>

      {/*  Pagination */}
      {movies && (
        <div className="flex justify-between w-9/12 items-center mt-4">
          <button
            className={`bg-blue-500 text-white px-4 py-2 rounded-md ${currentPage === 1 ? "opacity-50 cursor-not-allowed" : ""}`}
            disabled={currentPage === 1}
            onClick={() => getMoviesByName(currentPage - 1)}
          >
            Previous
          </button>
          {[...Array(pages)].map((_, index) => (
            <button
              key={index}
              className={`bg-blue-500 text-white px-4 py-2 ml-4 rounded-md ${index + 1 === currentPage ? "opacity-50" : ""}`}
              onClick={() => getMoviesByName(index + 1)}
            >
              {index + 1}
            </button>
          ))}
          <button
            className={`bg-blue-500 text-white px-4 py-2 rounded-md ${currentPage === pages ? "opacity-50 cursor-not-allowed" : ""}`}
            disabled={currentPage === pages}
            onClick={() => getMoviesByName(currentPage + 1)}
          >
            Next
          </button>
        </div>
      )}
    </div>
  );
}

export default Movies;

