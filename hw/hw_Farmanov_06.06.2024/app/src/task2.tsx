import React from "react";
import { useEffect, useState } from "react";
import { BlogInfo, NewsService } from "./Services/NewsService";

const Task2 = () => {
  const newsService = new NewsService();

  let [news, setNews] = useState<BlogInfo[]>([]);

  useEffect(() => {
    const fetchNews = async () => {
      try {
        const response = await newsService.GetNews("Food");
        setNews(response);
      } catch (e) {
        console.log("Error fetching movies", e);
      }
    };

    fetchNews();
  }, []);

  return (
    <div className="p-5 grid grid-cols-2 gap-4">
      {news.map((n) => blogCard(n))}
    </div>
  );
};

const blogCard = (card: BlogInfo) => {
  return (
    <a href={card.Url} className="flex flex-col justify-between gap-2 shadow w-[700px]">
      <div className="w-full">
        <img src={card.Thumbnail} className="w-full" />
      </div>
      <div className="p-2">
        <h1>{card.Date.toString()}</h1>
        <p>{card.Title}</p>
      </div>
    </a>
  )
}


export default Task2;
