import { createSlice, PayloadAction } from "@reduxjs/toolkit";
import { User } from "../../Entities/user";
import usersData from "../../data--ifVk2gibO0YVL3fSYmYd.json";

interface UsersState {
  users: User[];
}

const initialState: UsersState = {
  users: usersData,
};

const usersSlice = createSlice({
  name: "users",
  initialState: initialState,
  reducers: {
    updateData: (state, action: PayloadAction<User>) => {
      const index = state.users.findIndex((u) => u.id === action.payload.id);
      if (index !== -1) {
        state.users[index] = action.payload;
      }
      console.log("From users: ", state.users[index]);
    },
  },
});

export default usersSlice.reducer;
export const { updateData } = usersSlice.actions;
