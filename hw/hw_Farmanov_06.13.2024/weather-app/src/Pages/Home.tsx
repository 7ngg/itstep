import axios from "axios";
import { useEffect, useRef, useState } from "react";
import Button from "../Components/Button";
import Input from "../Components/Input";
import { Forecast } from "../Entities/forecast";

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
      // TODO: deal with caching

      localStorage.setItem("weatherData", JSON.stringify(r));
      setData(r);
    });
  };

  const getIcon = (code: string) => {
    return `https://openweathermap.org/img/wn/${code}@2x.png`;
  };

  return (
    <div>
      <header className="flex items-center gap-4 justify-center h-14 shadow bg-stone-800">
        <Input refs={cityRef} placeholder="City" />
        <Input refs={countryRef} placeholder="Country (optional)" />
        <Button text="Search" onClick={searchHandler} />
      </header>
      <main>
        {data && <h1>{Math.floor(data.main.temp - 272)}</h1>}
        <img src={getIcon(data!.weather[0].icon)}></img>
      </main>
    </div>
  );
};

export default Home;
