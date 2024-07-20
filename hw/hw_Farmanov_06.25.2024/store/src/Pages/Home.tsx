import { Outlet } from "react-router-dom";

const Home = () => {
  return (
    <div className="w-11/12 my-5 p-5 shadow bg-gray-50">
      <Outlet />
    </div>
  );
};

export default Home;
