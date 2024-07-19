import { Outlet } from "react-router-dom";
import Navbar from "../Components/navbar";
import routes from "../Routes";

const navItems = [
  {
    name: "Info",
    link: "",
  },
  {
    name: "Pictures",
    link: "pictures",
  },
  {
    name: "Attractions",
    link: "attractions",
  },
];

const Task1 = () => {
  return (
    <div>
      <header>
        <Navbar items={navItems} />
      </header>
      <main className="flex flex-col items-center">
        <Outlet />
      </main>
    </div>
  );
};

export default Task1;
