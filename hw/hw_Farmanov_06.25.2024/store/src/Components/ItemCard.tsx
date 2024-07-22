import { Categories } from "../Api/stock";

export interface cardProps {
  id: string;
  name: string;
  category: Categories;
  description: string;
  imgUrl: string;
  price: number;
}

const ItemCard = (props: cardProps) => {
  return (
    <div className="w-48 h-64 shadow rounded flex flex-col overflow-hidden p-2 hover:scale-[1.03] transition cursor-pointer">
      <div>
        <img src={props.imgUrl} alt={`${props.name}-img`} />
      </div>
      <div>
        <h1 className="text-xl font-bold">{props.name}</h1>
        <h2 className="text-lg text-gray-700"><span>&#36;</span>{props.price}</h2>
        <p
          className="text-ellipsis overflow-hidden"
          style={{
            display: "-webkit-box",
            WebkitBoxOrient: "vertical",
            WebkitLineClamp: 2,
          }}
        >
          {props.description}
        </p>
      </div>
    </div>
  );
};

export default ItemCard;
