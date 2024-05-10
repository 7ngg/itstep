import OmdbService from './Services/omdb-service.js'

const omdbService = new OmdbService(82130204);

const searchBtn = document.getElementById('search-btn');
const moreBtn = document.getElementById('more-btn');

const moviesList = document.getElementById('movies');

let moreBtnHandler;

searchBtn.onclick = async () => {
    const title = document.getElementById('query-title').value;
    const type = document.getElementById('query-type').value;

    if (!title) {
        return;
    }

    document.querySelector('.movies-container').style.display = 'flex';

    const response = await omdbService.getDataAsync(title, type);
    const movies = response.Search;

    moviesList.innerHTML = '';

    movies.forEach(movie => moviesList.insertAdjacentHTML(
        'beforeend',
        getTemplate(movie))
    );

    moreBtn.style.display = 'block';
    moreBtnHandler = loadMore(title, type);
};

moreBtn.onclick = () => {
    moreBtnHandler();
};

function loadMore(title, type) {
    let counter = 2;

    return async () => {
        const response = await omdbService.getDataAsync(title, type, counter);
        const movies = response.Search;

        movies.forEach(movie => moviesList.insertAdjacentHTML(
            'beforeend',
            getTemplate(movie))
        ); 

        counter += 1;
    }
}

function getTemplate(movie) {
    return `
        <div class="movie-card">
            <img class="movie-poster" src="${movie.Poster}" alt="">
            <h4 style="padding: 0;">${movie.Title}</h4>
            <p style="padding: 0;margin: 0;">${movie.Year}</p>
            <a class="btn" href="#">Details</a>
        </div>
    `;
}
