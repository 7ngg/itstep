import OmdbService from "./Services/omdb-service.js";

const omdbService = new OmdbService(82130204);

const searchBtn = document.getElementById("search-btn");
const moreBtn = document.getElementById("more-btn");
const exitBtn = document.getElementById('exit-btn');

const moviesList = document.getElementById("movies");

let moreBtnHandler;

searchBtn.onclick = async () => {
  const title = document.getElementById("query-title").value;
  const type = document.getElementById("query-type").value;

  if (!title) {
    return;
  }

  document.querySelector(".movies-container").style.display = "flex";

  const response = await omdbService.getDataAsync(title, type);
  const movies = response.Search;

  moviesList.innerHTML = "";

  movies.forEach((movie) => {
    moviesList.insertAdjacentHTML("beforeend", getTemplate(movie));

    document
      .getElementById(`${movie.imdbID}`)
      .addEventListener("click", async () => {
        document.querySelector('.popup-container').style.display = 'flex';
        const response = await omdbService.getDataByIdAsync(movie.imdbID);

        document.getElementById('popup-image').src = response.Poster;

        document.getElementById('popup-data-title').textContent = response.Title;
        document.getElementById('popup-data-released').textContent = response.Released;
        document.getElementById('popup-data-genre').textContent = response.Genre;
        document.getElementById('popup-data-country').textContent = response.Country;
        document.getElementById('popup-data-director').textContent = response.Director;
        document.getElementById('popup-data-writer').textContent = response.Writer;
        document.getElementById('popup-data-actors').textContent = response.Actors;
        document.getElementById('popup-data-awards').textContent = response.Awards;
      });
  });

  moreBtn.style.display = "block";
  moreBtnHandler = loadMore(title, type);
};

exitBtn.onclick = () => {
  document.querySelector('.popup-container').style.display = 'none';
}

moreBtn.onclick = () => {
  moreBtnHandler();
};

function loadMore(title, type) {
  let counter = 2;

  return async () => {
    const response = await omdbService.getDataAsync(title, type, counter);
    const movies = response.Search;

    movies.forEach((movie) =>
      moviesList.insertAdjacentHTML("beforeend", getTemplate(movie))
    );

    counter += 1;
  };
}

function getTemplate(movie) {
  return `
        <div class="movie-card">
            <img class="movie-poster" src="${movie.Poster}" alt="">
            <h4 style="padding: 0;">${movie.Title}</h4>
            <p style="padding: 0;margin: 0;">${movie.Year}</p>
            <a id="${movie.imdbID}" class="btn details-btn" href="#">Details</a>
        </div>
    `;
}
