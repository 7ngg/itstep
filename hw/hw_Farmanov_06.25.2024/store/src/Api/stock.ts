import { cardProps } from "../Components/ItemCard";
import data from "../data.json";

export function getData(): cardProps[] {
  console.log("fetched data")
  return data as cardProps[];
}

export function filterGet(category: string) {
  return getData().filter((i) => i.category === category);
}
