import Task1 from "./Task1";
import Attractions from "./Task1/attractions";
import Info from "./Task1/info";
import App from "./app";

const routes = [
  {
    path: "/",
    element: <App />,
  },
  {
    path: "task1",
    element: <Task1 />,
    children: [
      {
        path: "",
        element: <Info />,
      },
      {
        path: "Info",
        element: <Info />,
      },
      {
        path: "Attractions",
        element: <Attractions />,
      },
    ],
  },
];

export default routes;
