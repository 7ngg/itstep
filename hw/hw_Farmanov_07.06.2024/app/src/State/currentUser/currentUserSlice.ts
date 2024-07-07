import { createSlice, PayloadAction } from "@reduxjs/toolkit";
import { useSelector } from "react-redux";
import { User } from "../../Entities/user";
import { RootState } from "../store";

interface CurrentUserState {
  user: User;
}

const initialState: CurrentUserState = {
  user: { id: 0, name: "", email: "", age: 0 },
};

const currentUserSlice = createSlice({
  name: "currentUser",
  initialState: initialState,
  reducers: {
    set: (state, action: PayloadAction<User>) => {
      state.user = action.payload;
    },
    updateSelf: (state, action: PayloadAction<User>) => {
      state.user.name = action.payload.name;
      state.user.email = action.payload.email;
      state.user.age = action.payload.age;
      console.log("From current user: ", state.user)
    },
  },
});

export default currentUserSlice.reducer;
export const { set, updateSelf } = currentUserSlice.actions;
