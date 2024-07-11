import axios from "axios";
import { useEffect, useRef } from "react";
import Button from "../Components/Button";
import Input from "../Components/Input";

const Home = () => {
  const cityRef = useRef<HTMLInputElement>(null);
  const countryRef = useRef<HTMLInputElement>(null);

  const fetchData = (query: string) => {
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

    axios
      .request(options)
      .then((response) => console.log(response))
      .catch((e) => console.log(e));
  };

  useEffect(() => fetchData("Baki"), [])

  return (
    <div>
      <header className="flex items-center gap-4 justify-center h-14 shadow bg-stone-800">
        <Input ref={cityRef} placeholder="City" />
        <Input ref={countryRef} placeholder="Country (optional)" />
        <Button text="Search" />
      </header>
    </div>
  );
};

export default Home;

