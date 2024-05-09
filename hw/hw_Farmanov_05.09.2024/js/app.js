import OmdbService from './Services/omdb-service.js'

const omdbService = new OmdbService(82130204);

const response = await omdbService.getDataAsync('Batman', 'series')
console.log(response.Search)
