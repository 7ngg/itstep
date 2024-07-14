import axios from "axios";
import { useRef, useState } from "react";
import Button from "../Components/Button";
import Input from "../Components/Input";
import { Forecast } from "../Entities/forecast";

function convertUnixTimestampToTime(unixTimestamp: number): string {
  const milliseconds = unixTimestamp * 1000;

  const dateObject = new Date(milliseconds);

  const hours = dateObject.getHours().toString().padStart(2, "0"); // добавляем ведущий ноль, если часов меньше 10
  const minutes = dateObject.getMinutes().toString().padStart(2, "0"); // добавляем ведущий ноль, если минут меньше 10

  return `${hours}:${minutes}`;
}

const Home = () => {
  const cityRef = useRef<HTMLInputElement>(null);
  const countryRef = useRef<HTMLInputElement>(null);

  const [data, setData] = useState<Forecast>();

  const fetchData = (query: string): Promise<Forecast> => {
    const options = {
      method: "GET",
      url: "https://api.openweathermap.org/data/2.5/weather",
      params: {
        q: query,
        appid: "34dc774fd92b9a7dabcd0ae4067ef366",
      },
      headers: {
        accept: "application/json",
      },
    };

    return axios
      .request(options)
      .then((response) => {
        if (response.status !== 200) {
          throw Error(`Error fetching data. Status code ${response.status}`);
        }

        return response.data as Forecast;
      })
      .catch((e) => {
        console.log(e);
        throw e;
      });
  };

  const searchHandler = () => {
    if (!cityRef.current) {
      alert("Enter city name");
      return;
    }

    const city = cityRef.current.value;

    fetchData(city).then((r) => {
      setData(r);
    });
  };

  const getIcon = (code: string) => {
    return `https://openweathermap.org/img/wn/${code}@2x.png`;
  };

  return (
    <div className="flex flex-col items-center">
      <header className="flex items-center gap-4 w-full justify-center h-14 shadow bg-stone-800">
        <Input refs={cityRef} placeholder="City" />
        <Input refs={countryRef} placeholder="Country (optional)" />
        <Button text="Search" onClick={searchHandler} />
      </header>
      <main className="flex items-center">
        {data && (
          <div className="flex flex-col font-bold mt-5 border-solid border-2 rounded p-3">
            <div className="flex gap-1 text-3xl float-left">
              <h1>{data.name}, </h1>
              <h1>{data.sys.country}</h1>
            </div>
            <div className="flex items-center">
              <div className="flex flex-col font-bold">
                <h1 className="text-3xl font-bold">
                  {Math.floor(data.main.temp - 272)}
                  <span>&deg;</span>
                </h1>
                <p>{data.weather[0].description}</p>
              </div>
              <img src={getIcon(data.weather[0].icon)} alt="weather-icon" />
            </div>
            <div>
              <h1>Sunrise: {convertUnixTimestampToTime(data.sys.sunrise)}</h1>
              <h1>Sunset: {convertUnixTimestampToTime(data.sys.sunset)}</h1>
            </div>
          </div>
        )}
      </main>
    </div>
  );
};

export default Home;
