import Task1 from "./Task1";
import Attractions from "./Task1/attractions";
import InfoTask1 from "./Task1/info";
import InfoTask2 from "./Task2/info";
import App from "./app";
import Pictures from "./Task1/pictures";
import Task2 from "./Task2";
import Globe from "./Task2/globe";
import Plays from "./Task2/plays";
import Params from "./params";

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
        element: <InfoTask1 />,
      },
      {
        path: "Attractions",
        element: <Attractions />,
      },
      {
        path: "Pictures",
        element: <Pictures />,
      },
      {
        path: "params/:from/:parameter",
        element: <Params />,
      },
    ],
  },
  {
    path: "task2",
    element: <Task2 />,
    children: [
      {
        path: "",
        element: <InfoTask2 />,
      },
      {
        path: "Globe",
        element: <Globe />,
      },
      {
        path: "Plays",
        element: <Plays />,
      },
      {
        path: "params/:from/:parameter",
        element: <Params />,
      },
    ],
  },
];

export default routes;
