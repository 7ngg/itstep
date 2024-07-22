import { useMutation, useQuery, useQueryClient } from "@tanstack/react-query";
import { useEffect, useState } from "react";
import { Link, NavLink } from "react-router-dom";
import { getData } from "../Api/stock";
import ItemCard, { cardProps } from "../Components/ItemCard";
import { Categories } from "../Api/stock";

const categories = [
  "All",
  "Electronics",
  "Books",
  "Furniture",
  "Clothing",
  "Toys",
  "Garden",
  "Health",
  "Sports",
  "Automotive",
  "Beauty",
];

const Store = () => {
  const queryClient = useQueryClient();

  const [currerntCategory, setCurrentCategory] = useState<Categories>(
    Categories.All,
  );

  const { data: items, isLoading, refetch } = useQuery({
    queryFn: () => getData(currerntCategory),
    queryKey: ["items", { currerntCategory }],
  });

  if (isLoading) {
    return (
      <div className="w-11/12 my-5 p-5 shadow bg-gray-50 flex flex-wrap gap-5 items-center justify-center">
        <h1>Loading</h1>
      </div>
    );
  }

  const categoryHandler = (c: number) => {
    setCurrentCategory(c);
    refetch();
  }

  return (
    <div className="w-full flex flex-col gap-5 mt-5 justify-evenly">
      <div className="flex items-center justify-evenly bg-gray-50 h-16 px-2">
        {categories.map((c, index) => (
          <button
            key={index}
            onClick={() => categoryHandler(index)}
            className={`${c === Categories[currerntCategory] ? "bg-gray-200" : ""} w-36 py-2 hover:bg-gray-200 text-center rounded`}
          >
            {c}
          </button>
        ))}
      </div>
      <div className="flex flex-wrap gap-5 items-center justify-center bg-gray-50 p-5">
        {items?.map((i, index) => (
          <Link key={index} state={i} to={`/items/${i.id}`}>
            <ItemCard
              id={i.id}
              name={i.name}
              category={i.category}
              description={i.description}
              imgUrl={i.imgUrl}
              price={i.price}
            />
          </Link>
        ))}
      </div>
    </div>
  );
};

export default Store;
