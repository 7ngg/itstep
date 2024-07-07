import { configureStore } from "@reduxjs/toolkit";
import usersReducer from "./userEditing/userEditingSlice";
import currentUserReducer from "./currentUser/currentUserSlice";

export const store = configureStore({
  reducer: {
    users: usersReducer,
    currentUser: currentUserReducer,
  },
});

export type RootState = ReturnType<typeof store.getState>;
export type AppDispath = typeof store.dispatch;
