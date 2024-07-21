import { useEffect, useState } from "react";
import { getSummary, wikiResponse } from "../wikiApi";

const Info = () => {
  const [data, setData] = useState<wikiResponse>();

  const fetchSummary = async () => {
    const summary = await getSummary("Баку", 5);
    setData(summary);
  };

  useEffect(() => {
    fetchSummary();
  }, []);

  return (
    <div className="w-10/12 shadow p-5 flex flex-col gap-5 bg-gray-100">
      <img
        src="https://blog-cdn.aviata.kz/posts/thumbnails/0_011ebe663584bb0bf39cf77f3f5ddf2bc5daa925.webp"
        alt="city-img"
        className="m-2 rounded-lg shadow-lg transition-transform transform"
      />
      <p>{data?.data}</p>
    </div>
  );
};

export default Info;
