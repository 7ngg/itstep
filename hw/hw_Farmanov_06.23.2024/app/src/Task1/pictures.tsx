import React from "react";

const pics = [
  "https://i.imgur.com/uZYKxEY.jpeg",
  "https://i.imgur.com/LOrvjHR.jpeg",
  "https://i.imgur.com/jB5EVJ7.jpeg",
  "https://i.imgur.com/CzKByHt.jpeg",
  "https://i.imgur.com/CMbO2B6.jpeg",
];

const Pictures = () => {
  return (
    <div className="flex flex-wrap justify-center items-center h-screen p-4 bg-gray-100">
      {pics.map((p, index) => (
        <img
          src={p}
          alt={`img-${index}`}
          className="max-w-xs m-2 rounded-lg shadow-lg transition-transform transform hover:scale-105 hover:shadow-xl"
        />
      ))}
    </div>
  );
};

export default Pictures;
