import Error from "./Pages/Error";
import Home from "./Pages/Home";
import Store from "./Pages/Store";
import StoreItem from "./Pages/StoreItem";

const routes = [
  {
    path: "/",
    element: <Home />,
    errorElement: <Error />,
    children: [
      {
        path: "",
        element: <Store />,
      },
    ],
  },
  {
    path: "/items/:itemId",
    element: <StoreItem />,
  },
];

export default routes;
