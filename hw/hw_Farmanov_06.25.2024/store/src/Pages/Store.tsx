import { useQuery } from "@tanstack/react-query";
import { Link } from "react-router-dom";
import { getData } from "../Api/stock";
import ItemCard, { cardProps } from "../Components/ItemCard";

const Store = () => {
  const { data: items, isLoading } = useQuery({
    queryFn: () => getData(),
    queryKey: ["store-items"],
  });

  if (isLoading) {
    return (
      <div className="w-11/12 my-5 p-5 shadow bg-gray-50 flex flex-wrap gap-5 items-center justify-center">
        <h1>Loading</h1>
      </div>
    );
  }

  return (
    <div className="flex flex-wrap gap-5 items-center justify-center">
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
  );
};

export default Store;
