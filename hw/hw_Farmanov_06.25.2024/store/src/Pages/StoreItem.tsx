import { Link, useLocation } from "react-router-dom";
import { cardProps } from "../Components/ItemCard";

const StoreItem = () => {
  const location = useLocation();
  const item = location.state as cardProps;

  return (
    <div className="max-w-1/2 h-auto p-5 shadow rounded bg-gray-50 absolute top-1/2 left-1/2 translate-x-[-50%] translate-y-[-50%]">
      <div className="flex text-wrap gap-5">
        <div>
          <img src={item.imgUrl} alt={item.name} />
        </div>
        <div className="flex flex-col">
          <div className="flex gap-5">
            <div>
              <h1>Name:</h1>
              <h2>Price:</h2>
              <p>Description:</p>
            </div>
            <div>
              <h1>{item.name}</h1>
              <h2>{item.price}</h2>
              <p>{item.description}</p>
            </div>
          </div>
          <Link to="/" className="self-center bg-sky-400 w-32 py-2 rounded text-center absolute bottom-5 text-white">Back to store</Link>
        </div>
      </div>
    </div>
  );
};

export default StoreItem;
