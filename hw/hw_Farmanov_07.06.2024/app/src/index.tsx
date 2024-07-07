import React from "react";
import ReactDOM from "react-dom/client";
import "./index.css";
import Main from "./Pages/Main";
import { Provider } from "react-redux";
import { store } from "./State/store";
import { createBrowserRouter } from "react-router-dom";
import routes from "./routes";
import { RouterProvider } from "react-router";

const router = createBrowserRouter(routes)

const root = ReactDOM.createRoot(
  document.getElementById("root") as HTMLElement,
);
root.render(
  <React.StrictMode>
    <Provider store={store}>
      <RouterProvider router={router} />
    </Provider>
  </React.StrictMode>,
);
