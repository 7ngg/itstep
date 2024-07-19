import { Outlet } from "react-router-dom";
import Navbar from "../Components/navbar";

const navItems = [
  {
    name: "Info",
    link: "",
  },
  {
    name: "List of plays",
    link: "plays",
  },
  {
    name: "Shakespeare's Globe",
    link: "globe",
  },
];

const Task2 = () => {
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

export default Task2;
