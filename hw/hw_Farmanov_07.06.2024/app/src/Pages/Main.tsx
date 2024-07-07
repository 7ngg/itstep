import React from "react";
import { useDispatch, useSelector } from "react-redux";
import UserCard from "../Components/UserCard";
import { User } from "../Entities/user";
import { RootState } from "../State/store";
import EditingPage from "./editingPage";
import { useNavigate } from "react-router-dom";
import { set } from "../State/currentUser/currentUserSlice";

const Main = () => {
  const navigateTo = useNavigate();
  const dispatch = useDispatch();

  const users = useSelector((state: RootState) => state.users.users);

  const handler = (id: number) => {
    dispatch(set(users[id]))
    navigateTo("edit");
  };

  return (
    <div className="w-11/12 h-screen py-5 absolute left-0 right-0 ml-auto mr-auto shadow flex flex-col items-center overflow-scroll overflow-x-hidden">
      {users.map((u: User) => (
        <UserCard
          key={u.id}
          user={u}
          onClick={() => handler(users.indexOf(u))}
        />
      ))}
    </div>
  );
};

export default Main;
