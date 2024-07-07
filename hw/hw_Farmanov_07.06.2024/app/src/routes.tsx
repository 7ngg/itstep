import EditingPage from "./Pages/editingPage";
import Main from "./Pages/Main";

const routes = [
  {
    path: "/",
    element: <Main />,
  },
  {
    path: "/edit",
    element: <EditingPage />,
  },
];

export default routes;
