import { Outlet } from "react-router-dom";

const Home = () => {
  return (
    <div className="w-11/12">
      <Outlet />
    </div>
  );
};

export default Home;
