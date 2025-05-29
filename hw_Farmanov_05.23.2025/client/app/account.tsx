import { View, Text } from "react-native";
import AsyncStorage from "@react-native-async-storage/async-storage";
import { useEffect, useState } from "react";
import { SafeAreaView } from "react-native-safe-area-context";

interface User {
  id: string;
  username: string;
  imgUrl: string;
  memberForDays: number;
}

export default function Account() {
  const [user, setUser] = useState<User | null>(null);

  useEffect(() => {
    const fetchUser = async () => {
      const token = await AsyncStorage.getItem("accessToken");
      if (!token) return;

      try {
        const res = await fetch("http://192.168.100.3:8080/account", {
          method: "GET",
          headers: {
            Authorization: `Bearer ${token}`,
          },
        });

        if (!res.ok) {
          console.error("Failed to fetch user");
          return;
        }

        const data = await res.json();
        setUser(data);
      } catch (err) {
        console.error("Network error:", err);
      }
    };

    fetchUser();
  }, []);

  return (
    <SafeAreaView>
      <View>
        <Text>{user?.username}</Text>
      </View>
    </SafeAreaView>
  );
}
