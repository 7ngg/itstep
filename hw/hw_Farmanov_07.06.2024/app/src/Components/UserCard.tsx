import { User } from "../Entities/user";

interface UserCardProps {
  onClick: React.MouseEventHandler<HTMLDivElement>;
  user: User;
}

const UserCard = (props: UserCardProps) => {
  return (
    <div
      onClick={props.onClick}
      className="w-11/12 shadow rounded-md hover:scale-[1.03] hover:bg-slate-800 hover:text-white duration-75 cursor-pointer text-xl"
    >
      <div className="flex items-center w-full h-full justify-between px-10">
        <h1>{props.user.id}</h1>
        <p>{props.user.name}</p>
        <p>{props.user.email}</p>
        <p>{props.user.age}</p>
      </div>
    </div>
  );
};

export default UserCard;
