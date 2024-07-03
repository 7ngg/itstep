import { useState, useEffect, useRef } from "react";
import { City, CityInfoService } from "./Services/CityInfoService";

const Task3 = () => {
  let [city, setCity] = useState<City>();

  const cityInfoService = new CityInfoService();
  const queryRef = useRef<HTMLInputElement>(null);

  const handler = async (event: React.FormEvent<HTMLFormElement>) => {
    event.preventDefault();

    try {
      const query = queryRef.current?.value;

      if (!query) {
        throw Error("Invalid query");
      }

      const response = await cityInfoService.GetInfo(query);

      setCity(response);
      document.getElementById("cityInfo")!.style.display = "block";
    } catch (e) {
      console.log(e);
    }
  };

  return (
    <div className="h-[700px] w-[400px] shadow rounded-sm flex flex-col gap-5 items-center p-4">
      <h1 className="text-3xl">City data API</h1>
      <form className="w-9/12 flex flex-col gap-5" onSubmit={handler}>
        <div className="flex justify-between">
          <p className="text-xl">City:</p>
          <input
            ref={queryRef}
            className="shadow pl-2 rounded-sm"
            placeholder="name"
          />
        </div>
        <button
          type="submit"
          className="w-full rounded-sm text-white bg-blue-500"
        >
          Get data
        </button>
      </form>
      <div className="w-full hidden shadow-inner" id="cityInfo">
        <div key={city?.name}>
          <h2>City: {city?.name}</h2>
          <p>Country: {city?.country}</p>
          <p>Population: {city?.population}</p>
          <p>
            Coordinates: {city?.lat}, {city?.lng}
          </p>
        </div>
      </div>
    </div>
  );
};

export default Task3;
