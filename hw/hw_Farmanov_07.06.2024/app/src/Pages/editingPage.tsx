import { FormEvent, useEffect, useRef } from "react";
import { useDispatch, useSelector } from "react-redux";
import { Link, useNavigate } from "react-router-dom";
import Button from "../Components/Button";
import { User } from "../Entities/user";
import { updateSelf } from "../State/currentUser/currentUserSlice";
import { RootState } from "../State/store";
import { updateData } from "../State/userEditing/userEditingSlice";

const EditingPage: React.FC = () => {
  const navigateTo = useNavigate();
  const dispatch = useDispatch();

  const currentUser = useSelector((state: RootState) => state.currentUser.user);

  const nameRef = useRef<HTMLInputElement>(null);
  const emailRef = useRef<HTMLInputElement>(null);
  const ageRef = useRef<HTMLInputElement>(null);

  useEffect(() => {
    if (
      !nameRef.current?.placeholder ||
      !nameRef.current?.placeholder ||
      !nameRef.current?.placeholder
    ) {
      alert("No active user");
      navigateTo("/");
    }
  });

  const handler = (e: FormEvent<HTMLFormElement>) => {
    e.preventDefault();

    const updatedUser: User = {
      ...currentUser,
      name: nameRef.current?.value || currentUser.name,
      email: emailRef.current?.value || currentUser.email,
      age: Number(ageRef.current?.value) || currentUser.age,
    };

    dispatch(updateSelf(updatedUser));
    dispatch(updateData(updatedUser));

    navigateTo("/");
  };

  return (
    <div className="flex flex-col items-center justify-center w-1/3 shadow h-screen">
      <form
        className="flex flex-col gap-4 border p-10 w-9/12"
        onSubmit={handler}
      >
        <div>
          <h1>Name</h1>
          <input
            className="w-full pl-2 shadow h-[40px] rounded-md text-xl"
            type="text"
            ref={nameRef}
            placeholder={currentUser.name}
          />
        </div>
        <div>
          <h1>Email</h1>
          <input
            className="w-full pl-2 shadow h-[40px] rounded-md text-xl"
            type="email"
            ref={emailRef}
            placeholder={currentUser.email}
          />
        </div>
        <div>
          <h1>Age</h1>
          <input
            className="w-full pl-2 shadow h-[40px] rounded-md text-xl"
            type="number"
            ref={ageRef}
            placeholder={currentUser.age.toString()}
          />
        </div>
        <div className="flex w-1/2 self-center justify-between">
          <Link
            to="/"
            className="cursor-pointer bg-blue-500 w-24 h-7 flex items-center justify-center rounded-md text-white active:scale-[0.95] hover:bg-blue-600 shadow"
          >
            Cancel
          </Link>
          <Button text="Save" type="submit" />
        </div>
      </form>
    </div>
  );
};

export default EditingPage;
