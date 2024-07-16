import Navbar from "./Components/navbar";
import { Outlet } from "react-router-dom";

const links = [
  {
    name: "Task 1",
    link: "task1",
  },
  {
    name: "Task 2",
    link: "",
  },
];

const App = () => {
  return (
    <div>
      <header>
        <Navbar items={links} />
      </header>
      <main>
        <Outlet />
      </main>
    </div>
  );
};

export default App;
